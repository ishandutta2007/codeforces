#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <complex>
using namespace std;

void solve();
#define mp make_pair
#define pb push_back
int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
typedef long long int li;
#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

struct sob{
    int time;
    bool type; //0- , true
    int okno_type;
    int id;
    int cnt;
    sob(int time,bool type,int okno_type,int id,int cnt){
        this->time=time;
        this->type=type;
        this->okno_type=okno_type;
        this->id=id;
        this->cnt=cnt;
    }
    bool operator< (const sob& b){
        return time<b.time || (time==b.time&& type<b.type) || (time==b.time && type==b.type && id<b.id) || (time==b.time && type==b.type && id== b.id && cnt<b.cnt);    
    }
    sob(){}
};
struct pq{
    sob a[300000];
    int cntt;
    pq(){
        cntt=0;
    }
    sob top(){
        return a[1];
    }
    void pop(){
        swap(a[1],a[cntt--]);
        down(1);
    }
    void down(int i){
        if(2*i==cntt){
            if(a[2*i]<a[i]){
                swap(a[i],a[2*i]);
                down(2*i);
            }
        }
        else if(2*i<cntt){
            int t=2*i;
            if(a[t+1]<a[t])
                ++t;
            if(a[t]<a[i]){
                swap(a[i],a[t]);
                down(t);
            }
        }
    }
    bool empty(){
        return !cntt;
    }
    void up(int i){
        if(i<2)
            return;
        if(a[i]<a[i/2]){
            swap(a[i],a[i/2]);
            up(i/2);
        }
    }
    void push(const sob& b){
        a[++cntt]=b;
        up(cntt);
    }
};
void solve(){
    int k[3],t[3],cnt=0;    
    for(int i=0;i<3;++i)
        cin>>k[i];
    for(int i=0;i<3;++i)
        cin>>t[i];
    int n;
    int c[101010];
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%I64d",c+i);
    }
    sort(c,c+n);
    pq q;
    
    queue<int> wait[3];
    for(int i=0;i<n;++i){
        q.push(sob(c[i],true,0,i,cnt++));
    }
    int ans=0;
    while(!q.empty()){
        sob cur=q.top();
        q.pop();
        if(cur.type){
            if(!k[cur.okno_type]){
                wait[cur.okno_type].push(cur.id);
                continue;
            }
            --k[cur.okno_type];
            q.push(sob(cur.time+t[cur.okno_type],0,cur.okno_type,cur.id,cnt++));
        }
        else{
            if(cur.okno_type==2){
                ans=max(ans,cur.time-c[cur.id]);
            }
            else{
                q.push(sob(cur.time,1,cur.okno_type+1,cur.id,cnt++));
            }
            if(wait[cur.okno_type].empty()){
                ++k[cur.okno_type];
            }
            else{
                q.push(sob(cur.time+t[cur.okno_type],0,cur.okno_type,wait[cur.okno_type].front(),cnt++));
                wait[cur.okno_type].pop();
            };
        }
    }
    cout<<ans;
}