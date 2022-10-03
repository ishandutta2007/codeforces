#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        string S;cin>>S;
        vector<int> cnt(3,0),last(3,0);
        for(int i=0;i<S.size();i++){
            if('a'<=S[i]&&S[i]<='z'){
                cnt[0]++;
                last[0]=i;
            }
            else if('A'<=S[i]&&S[i]<='Z'){
                cnt[1]++;
                last[1]=i;
            }
            else if('0'<=S[i]&&S[i]<='9'){
                cnt[2]++;
                last[2]=i;
            }
        }
        
        if(cnt[0]&&cnt[1]&&cnt[2]) cout<<S<<endl;
        else{
            if(cnt[0]&&cnt[1]==0&&cnt[2]==0){
                S[0]='A';
                S[1]='0';
                cout<<S<<endl;
            }else if(cnt[0]==0&&cnt[1]&&cnt[2]==0){
                S[0]='a';
                S[1]='0';
                cout<<S<<endl;
            }else if(cnt[0]==0&&cnt[1]==0&&cnt[2]){
                S[0]='a';
                S[1]='A';
                cout<<S<<endl;
            }else if(cnt[0]&&cnt[1]){
                if(cnt[0]>=2){
                    S[last[0]]='0';
                }else{
                    S[last[1]]='0';
                }
                cout<<S<<endl;
            }else if(cnt[0]&&cnt[2]){
                if(cnt[0]>=2){
                    S[last[0]]='A';
                }else{
                    S[last[2]]='A';
                }
                cout<<S<<endl;
            }else if(cnt[1]&&cnt[2]){
                if(cnt[1]>=2){
                    S[last[1]]='a';
                }else{
                    S[last[2]]='a';
                }
                cout<<S<<endl;
            }
        }
        
        T--;
    }
}