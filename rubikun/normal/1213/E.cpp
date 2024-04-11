#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S,T;cin>>S>>T;
    cout<<"YES"<<endl;
    if(T[0]==T[1]) swap(S,T);
    
    if(S[0]==S[1]){
        if(T[0]==T[1]){
            for(int i=0;i<N;i++){
                cout<<"abc";
            }
            cout<<endl;
        }else if(T[0]==S[0]){
            int a=S[0]-'a',b=T[1]-'a',c=3-(a+b);
            for(int i=0;i<N;i++){
                cout<<char('a'+a)<<char('a'+c)<<char('a'+b);
            }
            cout<<endl;
        }else if(T[1]==S[0]){
            int a=S[0]-'a',b=T[0]-'a',c=3-(a+b);
            for(int i=0;i<N;i++){
                cout<<char('a'+a)<<char('a'+b)<<char('a'+c);
            }
            cout<<endl;
        }else if(T[0]!=T[1]){
            for(int i=0;i<N;i++){
                cout<<S[0]<<T[1]<<T[0];
            }
            cout<<endl;
        }
    }else{
        if(S[0]==T[0]&&S[1]==T[1]){
            int a=S[0]-'a',b=S[1]-'a',c=3-(a+b);
            for(int i=0;i<N;i++){
                cout<<char('a'+a);
            }
            for(int i=0;i<N;i++){
                cout<<char('a'+c);
            }
            for(int i=0;i<N;i++){
                cout<<char('a'+b);
            }
            cout<<endl;
        }else if(S[0]==T[1]&&S[1]==T[0]){
            int a=S[0]-'a',b=S[1]-'a',c=3-(a+b);
            for(int i=0;i<N;i++){
                cout<<char('a'+a);
            }
            for(int i=0;i<N;i++){
                cout<<char('a'+c);
            }
            for(int i=0;i<N;i++){
                cout<<char('a'+b);
            }
            cout<<endl;
        }else if(S[1]==T[0]){
            for(int i=0;i<N;i++){
                cout<<S[0];
            }
            for(int i=0;i<N;i++){
                cout<<T[1];
            }
            for(int i=0;i<N;i++){
                cout<<S[1];
            }
            cout<<endl;
        }else if(S[0]==T[1]){
            for(int i=0;i<N;i++){
                cout<<T[0];
            }
            for(int i=0;i<N;i++){
                cout<<S[1];
            }
            for(int i=0;i<N;i++){
                cout<<T[1];
            }
            cout<<endl;
        }else if(S[0]==T[0]){
            for(int i=0;i<N;i++){
                cout<<S[1];
            }
            for(int i=0;i<N;i++){
                cout<<T[1];
            }
            for(int i=0;i<N;i++){
                cout<<S[0];
            }
            cout<<endl;
        }else if(S[1]==T[1]){
            for(int i=0;i<N;i++){
                cout<<S[1];
            }
            for(int i=0;i<N;i++){
                cout<<S[0];
            }
            for(int i=0;i<N;i++){
                cout<<T[0];
            }
            cout<<endl;
        }
    }
}