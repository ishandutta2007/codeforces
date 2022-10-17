#include <iostream>
#include <stack>
using namespace std;

const int MAXN = 605;

int N, K;
int L[MAXN], R[MAXN];

stack<int> idx, loc;
string ans;

int main(){
    cin >> N;

    for(int i = 0; i<N; i++){
        cin >> L[i] >> R[i];
        idx.push(i);
        loc.push(K);
    
        ans += '(';
        K++;
    
        while(idx.size()){
            int c = idx.top();
            int p = loc.top();
            
            if(p + R[c] < K){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            
            if(p + L[c] > K) break;
      
            idx.pop();
            loc.pop();
            ans += ')';
            K++;
        }
    }
  
    cout << (idx.size() ? "IMPOSSIBLE" : ans) << endl;
}