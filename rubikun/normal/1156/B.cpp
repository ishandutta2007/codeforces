#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        string A,B,S;cin>>S;
        int N=S.size();
        for(int i=0;i<N;i++){
            if((S[i]-'a')%2==1) A+=S[i];
            else B+=S[i];
        }
        sort(all(A));
        sort(all(B));
        if(A.size()==0) cout<<B<<endl;
        else if(B.size()==0) cout<<A<<endl;
        else{
            bool ok=false;
            for(int i=0;i<A.size();i++){
                for(int j=0;j<B.size();j++){
                    if(abs(A[i]-B[j])!=1){
                        ok=true;
                        for(int x=0;x<A.size();x++){
                            if(x==i) continue;
                            cout<<A[x];
                        }
                        cout<<A[i];
                        cout<<B[j];
                        for(int y=0;y<B.size();y++){
                            if(y==j) continue;
                            cout<<B[y];
                        }
                        cout<<endl;
                        break;
                    }
                }
                if(ok) break;
            }
            if(!ok) cout<<"No answer"<<endl;
        }
    }
}