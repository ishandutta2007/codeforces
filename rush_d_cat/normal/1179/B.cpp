#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 600000 + 10;

int n,m;
vector< pair<int,int> > vec;
int solve(int r1,int r2) {
    vector< pair<int,int> > tmp;
    int sgn=1;
    for(int i=m-1;i>=((r1==r2)?1:0);i--){
        tmp.push_back(make_pair(sgn*(r2-r1),sgn*i));
        //printf("in %d %d\n", sgn*(r2-r1),i);
        sgn*=-1; 
    }
    if(r1!=r2) { 
        int sz=tmp.size();
        for(int i=sz-2;i>=0;i--){
            tmp.push_back(make_pair(tmp[i].first, tmp[i].second*-1));
        }
    }
    for(auto p: tmp) vec.push_back(p);
}
int main() {
    cin>>n>>m;
    int sgn=1;
    for(int i=1;i<=n;i++){
        if(i<=n-i+1) {
            solve(i,n-i+1);
            if(i+1<n-i+1){
                vec.push_back(make_pair(-(n-i+1-i-1),0));
            } 
        }
    }
    int x=1,y=1;
    printf("%d %d\n", x,y);
    for(auto p: vec) {
        x += p.first, y += p.second;
        printf("%d %d\n", x, y);
    }
}