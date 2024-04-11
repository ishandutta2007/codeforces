#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;
const ll INF=1LL<<60;
 
struct point{
    ll x;
    ll y;
    ll z;
    int num;
};
 
bool compare(point a,point b){
    if(a.z==b.z){
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    }
    return a.z<b.z;
}
 
int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<point> P(N);
    vector<int> used(N+1,0);
    for(int i=0;i<N;i++){
        cin>>P[i].x>>P[i].y>>P[i].z;
        P[i].num=i+1;
    }
    
    sort(all(P),compare);
    
    for(int i=0;i<N-1;i++){
        int ok=i;
        while(ok<N&&P[i].z==P[ok].z) ok++;
        ok--;
        if(i==ok) continue;
        
        for(int j=i;j<ok;j++){
            int ok2=j;
            while(ok2<=ok&&P[j].x==P[ok2].x) ok2++;
            ok2--;
            if(j==ok2) continue;
            for(int k=j;k+1<=ok2;k+=2){
                cout<<P[k].num<<" "<<P[k+1].num<<endl;
                used[P[k].num]=1;
                used[P[k+1].num]=1;
            }
            j=ok2;
        }
        int left=-1;
        for(int j=i;j<=ok;j++){
            if(used[P[j].num]==0){
                if(left==-1) left=j;
                else{
                    cout<<P[left].num<<" "<<P[j].num<<endl;
                    used[P[left].num]=1;
                    used[P[j].num]=1;
                    left=-1;
                }
            }
        }
        i=ok;
    }
    
    int left=-1;
    
    for(int i=0;i<N;i++){
        if(used[P[i].num]==0){
            if(left==-1) left=i;
            else{
                cout<<P[left].num<<" "<<P[i].num<<endl;
                used[P[left].num]=1;
                used[P[i].num]=1;
                left=-1;
            }
        }
    }
    
}