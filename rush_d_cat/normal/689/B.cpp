#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef __int64 ll;
typedef pair<int,int> P;
const int INF=100000000;
const int maxn = 200000+10;
int to[maxn];
int d[maxn],N;
void bfs()
{
    for(int i=1;i<=N;i++) d[i]=INF;
    queue<int> q;
    q.push(1);d[1]=0;
    while(q.size())
    {
        int x=q.front();q.pop();
        int nx;
        nx=x+1;
        if(1<=nx&&nx<=N&&d[nx]==INF){
            q.push(nx);
            d[nx]=d[x]+1;
        }
        nx=x-1;
        if(1<=nx&&nx<=N&&d[nx]==INF){
            q.push(nx);
            d[nx]=d[x]+1;
        }
        nx=to[x];
        if(1<=nx&&nx<=N&&d[nx]==INF){
            q.push(nx);
            d[nx]=d[x]+1;
        }
    }
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>to[i];
    }
    bfs();
    for(int i=1;i<=N;i++){
        cout<<d[i];
        if(i==N) cout<<endl;
        else cout<<" ";
    }
}