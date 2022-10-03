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
const int mod=1000000007,MAX=2005,INF=1<<30;

void ask(int x,int y){
    cout<<x<<" "<<y<<endl;
}

void output(int x1,int y1,int x2,int y2){
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}

int input(){
    string S;cin>>S;
    if(S=="black") return 1;
    else return 0;
}

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);*/
    
    int N;cin>>N;
    if(N==1){
        ask(1,0);
        input();
        output(1,1,2,1);
        return 0;
    }
    vector<int> res(N);
    ask(1,1<<28);
    res[0]=input();
    ask(1,(1<<28)*2);
    res[1]=input();
    
    if(N==2){
        if(res[0]==res[1]) output(1,0,2,0);
        else output(1,(1<<28)+(1<<27),2,(1<<28)+(1<<27));
        
        return 0;
    }
    
    int left,right;
    
    if(res[0]==res[1]){
        left=(1<<28)*2;
        right=(1<<28)*3;
    }else{
        left=(1<<28);
        right=(1<<28)*2;
    }
    
    for(int i=2;i<N;i++){
        int mid=(left+right)/2;
        ask(1,mid);
        res[i]=input();
        
        if(res[i]==res[0]) left=mid;
        else right=mid;
    }
    
    output(0,left,2,left+1);
    
    return 0;
}