#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int N, Q;
ll B;
int size[MAXN];
int endp[MAXN];

int rlen(int i){
    return (endp[i] + N - i) % N + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> Q;

    for(int i=0; i<N; i++)
        cin >> size[i];

    for(int q=0; q<Q; q++){
        cin >> B;

        int mr = -1, ml = 0x7fffffff;

        ll sum = 0, j = -1;
        for(int i=0; i<N; i++){
            if(i) sum -= size[i-1];
        
            if(j==(i-1)){
                j = i;
                sum += size[i];
            }

            while(true){
                int k = (j+1)%N;
                if(k==i) break;
                if(sum + size[k] > B) break;
                sum += size[k];
                j = k; 
            }

            endp[i] = j;

            bool maxi = (sum + size[(i-1+N)%N] > B) or rlen(i) == N;
            if(maxi and rlen(i) < ml){
                ml = rlen(i);
                mr = i;
            }
        }
    
        int ans = 0x7fffffff;
        for(int s=mr; true; s = (s+1)%N){
            int use = 1, rch = rlen(s);
            while(rch < N){
                use++;
                rch += rlen((s+rch)%N);
            }
            ans = min(ans, use);

            if(s == endp[mr]) break;
        }
        cout << ans << endl;
    }
}