#include <iostream>
using namespace std;

int N, Q, T, A, B;
int bit[100005];
int dir = 1, sta = 0;

int read(int k){
    int sum = 0;
    while(k > 0){
        sum += bit[k];
        k -= (k & -k);
    }
    return sum;
}

void update(int i, int v){
    while(i <= N){
        bit[i]+=v;
        i += (i & -i);
    }
}

int main(){
    cin >> N >> Q;
    int L = N;

    N += 1;
    for(int i=1; i<=L; i++)
        update(i, 1);

    for(int i=0; i<Q; i++){
        cin >> T;
        if(T == 1){
            cin >> A;

            if(A > (L-A)){
                sta += dir * (L + 1);
                A = L - A;
                dir *= -1;
            }

            for(int of=1; of<=A; of++){
                int val = read(sta + of * dir) - read(sta + of * dir - 1);
                update(sta + of * dir, -1 * val);
                update(sta + (A + A + 1 - of) * dir, val);
            }
            sta += A * dir;
            L -= A;

        }
        else{
            cin >> A >> B;
            if(dir == 1) cout << read(sta + B) - read(sta + A) << endl;
            else cout << read(sta - A - 1) - read(sta - B - 1) << endl;
        }
    }

    return 0;
}