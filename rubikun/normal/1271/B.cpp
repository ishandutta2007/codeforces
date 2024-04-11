#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string S;cin>>S;
    
    int cntb=0,cntw=0;
    
    for(int i=0;i<N;i++){
        if(S[i]=='B') cntb++;
        else cntw++;
    }
    
    if(cntb%2&&cntw%2){
        cout<<-1<<endl;
        return 0;
    }
    
    if(cntb%2==0){
        vector<int> ans;
        for(int i=0;i<N-1;i++){
            if(S[i]=='B'){
                ans.push_back(i+1);
                S[i]='W';
                
                S[i+1]=char('B'+'W'-S[i+1]);
            }
        }
        cout<<ans.size()<<endl;
        for(int a:ans) cout<<a<<" ";
        cout<<endl;
        return 0;
    }
    
    if(cntw%2==0){
        vector<int> ans;
        for(int i=0;i<N-1;i++){
            if(S[i]=='W'){
                ans.push_back(i+1);
                S[i]='B';
                
                S[i+1]=char('B'+'W'-S[i+1]);
            }
        }
        cout<<ans.size()<<endl;
        for(int a:ans) cout<<a<<" ";
        cout<<endl;
        return 0;
    }
    
}