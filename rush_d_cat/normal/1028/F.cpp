#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int N = 200000+10;

int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}
int q,n;
map< pair<int,int>, int > mp, mp2;
map<LL, set< pair<int,int> > > st;

int main() {
    scanf("%d", &q);
    while(q --) {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1) {
            n ++;
            LL c=1LL*x*x+1LL*y*y;
            for(auto p: st[c]) {
                LL midx = x + p.first;
                LL midy = y + p.second;
                LL g = gcd(midx, midy);
                midx /= g, midy /= g;
                mp[make_pair(midx,midy)] ++;
            }
            st[c].insert(make_pair(x,y));
            LL g=gcd(x,y); x/=g, y/=g; mp2[make_pair(x,y)] ++;
        } else if(op==2) {
            n --;
            LL c=1LL*x*x+1LL*y*y;
            st[c].erase(make_pair(x,y));
            for(auto p: st[c]) {
                LL midx = x + p.first;
                LL midy = y + p.second;
                LL g = gcd(midx, midy);
                midx /= g, midy /= g;
                mp[make_pair(midx,midy)] --;
            }
    
            LL g=gcd(x,y); x/=g, y/=g; mp2[make_pair(x,y)] --;
        } else {
            //printf("n = %d\n", n);
            LL g = gcd(x, y); x/=g, y/=g;
            //printf("%d %d\n", mp[make_pair(x,y)], mp2[make_pair(x,y)]);
            printf("%d\n", n-2*mp[make_pair(x,y)]-mp2[make_pair(x,y)]);
        }
    }
}