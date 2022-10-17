#include <iostream>
using namespace std;

int M, N;
long long T, S = 0;
long long l[100005], r[100005];
long long len[100005], val[100005];
bool v[100005];

long long find(long long idx){
    int low = 0, high = M-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(idx < l[mid]) high = mid-1;
        else if(idx > r[mid]) low = mid+1;
        else{
            if(v[mid]) return val[mid];
            return find((idx - l[mid])%len[mid] + 1);
        }
    }
    return 0;
}

int main(){
    cin >> M;
    
    for(int i=0; i<M; i++){
        cin >> T;
        v[i] = (T==1);

        l[i] = S + 1;
        if(v[i]){
            cin >> val[i];
            r[i] = S + 1;
        }
        else{
            cin >> len[i] >> val[i];
            r[i] = S + len[i] * val[i];
        }
        S = r[i];
    }

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T;
        cout << find(T) << " ";
    }
    cout << endl;
    return 0;
}