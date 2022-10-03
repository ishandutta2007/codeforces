#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

int ask(string S){
    cout<<S<<endl;
    int x;cin>>x;
    return x;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string al(N,'T');
    int zen=ask(al);
    string kougo(N,'.');
    for(int i=0;i<N;i++){
        if(i%3==1) kougo[i]='F';
        else kougo[i]='T';
    }
    int kou=ask(kougo);
    
    string ans;
    
    for(int s=0;s<N;s+=3){
        if(s==N-1){
            string chan=al;
            chan[s]='F';
            int x=ask(chan);
            if(x+1==zen) ans+="T";
            else ans+="F";
            continue;
        }
        if(s==N-2){
            string chan=al;
            for(int i=s;i<s+2;i++) chan[i]='F';
            int x=ask(chan);
            if(x+2==zen) ans+="TT";
            else if(x==zen){
                chan[s]='T';
                int y=ask(chan);
                if(y+1==x) ans+="FT";
                else ans+="TF";
            }else{
                ans+="FF";
            }
            continue;
        }
        string chan=al;
        for(int i=s;i<s+3;i++) chan[i]='F';
        int x=ask(chan);
        if(x+3==zen){
            ans+="TTT";
            continue;
        }
        if(x-3==zen){
            ans+="FFF";
            continue;
        }
        if(x+1==zen){
            string nex=kougo;
            nex[s]='F';
            nex[s+1]='T';
            int y=ask(nex);
            if(y+2==kou){
                ans+="TFT";
            }else if(y==kou){
                ans+="TTF";
            }else{
                ans+="FTT";
            }
            continue;
        }
        // TTF TFT FTT
        if(x-1==zen){
            string nex=kougo;
            nex[s]='F';
            nex[s+1]='T';
            int y=ask(nex);
            if(y+2==kou){
                ans+="TFF";
            }else if(y==kou){
                ans+="FFT";
            }else{
                ans+="FTF";
            }
            continue;
        }
        // TFF FTF FFT
    }
    
    ask(ans);
    
    return 0;
}