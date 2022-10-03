#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S,T;cin>>S>>T;
    vector<int> ab,ba;
    for(int i=0;i<N;i++){
        if(S[i]=='a'&&T[i]=='b') ab.push_back(i+1);
        else if(S[i]=='b'&&T[i]=='a') ba.push_back(i+1);
    }
    
    if((ab.size()+ba.size())%2==1){
        cout<<-1<<endl;
        return 0;
    }
    
    if(ab.size()%2==0){
        cout<<ab.size()/2+ba.size()/2<<endl;
        for(int i=0;i+1<ab.size();i+=2){
            cout<<ab[i]<<" "<<ab[i+1]<<endl;
        }
        for(int i=0;i+1<ba.size();i+=2){
            cout<<ba[i]<<" "<<ba[i+1]<<endl;
        }
    }else{
        cout<<ab.size()/2+ba.size()/2+2<<endl;
        for(int i=0;i+1<ab.size();i+=2){
            cout<<ab[i]<<" "<<ab[i+1]<<endl;
        }
        for(int i=0;i+1<ba.size();i+=2){
            cout<<ba[i]<<" "<<ba[i+1]<<endl;
        }
        cout<<ba.back()<<" "<<ba.back()<<endl;
        cout<<ab.back()<<" "<<ba.back()<<endl;
    }
    
}