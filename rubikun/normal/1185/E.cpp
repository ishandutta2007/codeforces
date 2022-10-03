#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000005,INF=2000000003;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int q=0;q<T;q++){
        int N,M;cin>>N>>M;
        vector<string> S(N);
        for(int i=0;i<N;i++){
            cin>>S[i];
        }
        
        vector<int> z1,z2,z3,z4;
        
        bool deta=false,ok=true;
        
        for(int k=25;k>=0;k--){
            set<int> A,B;
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    if(S[i][j]=='a'+k){
                        A.insert(i);
                        B.insert(j);
                    }
                }
            }
            if(A.size()==0&&B.size()==0){
                if(deta){
                    bool flag=false;
                    for(int i=0;i<N;i++){
                        for(int j=0;j<M;j++){
                            if(S[i][j]=='#'){
                                z1.push_back(i+1);
                                z2.push_back(j+1);
                                z3.push_back(i+1);
                                z4.push_back(j+1);
                                flag=true;
                            }
                            if(flag) break;
                        }
                        if(flag) break;
                    }
                }
            }else if(A.size()>=2&&B.size()>=2) ok=false;
            else if(B.size()==1){
                int a=*A.begin(),b=a,c=*B.begin();
                for(auto it=A.begin();it!=A.end();it++){
                    b=*it;
                }
                for(int i=a;i<=b;i++){
                    if(S[i][c]!='#'&&S[i][c]!='a'+k) ok=false;
                    S[i][c]='#';
                }
                z1.push_back(a+1);
                z2.push_back(c+1);
                z3.push_back(b+1);
                z4.push_back(c+1);
                deta=true;
            }else if(A.size()==1){
                int a=*B.begin(),b=a,c=*A.begin();
                for(auto it=B.begin();it!=B.end();it++){
                    b=*it;
                }
                for(int j=a;j<=b;j++){
                    if(S[c][j]!='#'&&S[c][j]!='a'+k) ok=false;
                    S[c][j]='#';
                }
                z1.push_back(c+1);
                z2.push_back(a+1);
                z3.push_back(c+1);
                z4.push_back(b+1);
                deta=true;
            }
        }
        
        reverse(all(z1));
        reverse(all(z2));
        reverse(all(z3));
        reverse(all(z4));
        
        if(ok){
            cout<<"YES\n";
            cout<<z1.size()<<"\n";
            
            for(int i=0;i<z1.size();i++){
                cout<<z1[i]<<" "<<z2[i]<<" "<<z3[i]<<" "<<z4[i]<<"\n";
            }
        }else cout<<"NO\n";
    }
    
}