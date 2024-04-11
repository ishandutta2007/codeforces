#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K;
int v[205];

int main(){
    cin >> N >> K;
    for(int i = 0; i<N; i++)
        cin >> v[i];

    int ans = -1000000007;
    priority_queue<int> in, out;
        
    for(int l = 0; l<N; l++)
        for(int r = l; r<N; r++){        
            while(!in.empty()) in.pop();
            while(!out.empty()) out.pop();
            
            int in_sum = 0;
            
            for(int i = 0; i<N; i++){
                if(l<=i && i<=r){
                    in.push(-1 * v[i]);
                    in_sum += v[i];
                }
                else out.push(v[i]);
            }
            
            for(int k = 0; k<K; k++){
                if(in.empty() || out.empty()) continue;
                if((-1 * in.top()) < out.top()){
                    int in_pop = -1 * in.top(); in.pop();
                    int out_pop = out.top(); out.pop();
                
                    in_sum -= in_pop;
                    in_sum += out_pop;
                    
                    in.push(out_pop * -1);
                    out.push(in_pop);
                }
                else break;
            }
            
            ans = max(ans, in_sum);
        }
    
    cout << ans << endl;
    return 0;
}