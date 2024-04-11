#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=3005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T){
        int N;cin>>N;
        vector<string> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        
        int cnt=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j) continue;
                if(A[i]==A[j]){
                    bool changed=false;
                    for(int k=0;k<4;k++){
                        for(int l=0;l<10;l++){
                            char mae=A[i][k];
                            if(A[i][k]==char('0'+l)) continue;
                            A[i][k]=char('0'+l);
                            bool ok=true;
                            for(int x=0;x<N;x++){
                                if(x==i) continue;
                                if(A[i]==A[x]) ok=false;
                            }
                            if(ok){
                                cnt++;
                                changed=true;
                                break;
                            }else{
                                A[i][k]=mae;
                            }
                        }
                        if(changed) break;
                    }
                }
            }
        }
        
        cout<<cnt<<"\n";
        for(int i=0;i<N;i++){
            cout<<A[i]<<"\n";
        }
        
        T--;
    }
}