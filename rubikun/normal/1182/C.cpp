#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
string U="aeiou";
vector<string> S[1000003][5];
int sum[1000003];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    for(int i=0;i<N;i++){
        string a;cin>>a;
        int cnt=0;
        int last=-1;
        for(int j=0;j<a.size();j++){
            for(int k=0;k<5;k++){
                if(a[j]==U[k]){
                    cnt++;
                    last=k;
                }
            }
        }
        S[cnt][last].push_back(a);
    }
    
    int fi=0,se=0;
    for(int i=0;i<1000003;i++){
        int su=0;
        for(int j=0;j<5;j++){
            se+=S[i][j].size()/2;
            su+=S[i][j].size();
        }
        fi+=su/2;
        sum[i]=su;
    }
    
    int ans=min(fi/2,se);
    cout<<ans<<endl;
    
    vector<string> A,B;
    
    for(int i=0;i<1000003;i++){
        if(B.size()==ans*2) break;
        for(int j=0;j<5;j++){
            for(int k=0;k+1<S[i][j].size();k+=2){
                if(B.size()==ans*2) break;
                
                B.push_back(S[i][j][k]);
                B.push_back(S[i][j][k+1]);
                
                S[i][j][k]="";
                S[i][j][k+1]="";
            }
        }
    }
    
    for(int i=0;i<1000003;i++){
        if(A.size()==ans*2) break;
        vector<string> C;
        for(int j=0;j<5;j++){
            for(int k=0;k<S[i][j].size();k++){
                if(S[i][j][k].size()==0) continue;
                C.push_back(S[i][j][k]);
            }
        }
        for(int k=0;k+1<C.size();k+=2){
            if(A.size()==ans*2) break;
            A.push_back(C[k]);
            A.push_back(C[k+1]);
        }
    }
    
    for(int i=0;i<ans*2;i++){
        cout<<A[i]<<" "<<B[i]<<"\n";
    }
    
}