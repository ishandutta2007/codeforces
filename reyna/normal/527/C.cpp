//In the name of God
#include <iostream>
#include <set>
#include <cstdio>
#include <map>
using namespace std;
multiset<int,greater<int> > ver;
multiset<int,greater<int> > hor;
map<int,int> mpv;
map<int,int> mph;
set<int> verp;
set<int> horp;
int main(){
    int n,m,q;
    cin >> n >> m >> q;
    ver.insert(n);
    hor.insert(m);
    verp.insert(0);
    verp.insert(n);
    mpv[n]++;
    mph[m]++;
    horp.insert(0);
    horp.insert(m);
    for(int i = 0; i < q;i++){
        char ch;
        int x;
        cin >> ch;
        scanf("%d",&x);
        if(ch == 'H'){
            set<int>::iterator it = horp.lower_bound(x);
            int next = *it;
            --it;
            int prev = *it;
            if(!(--mph[next-prev]))
                hor.erase(next-prev);
            if(!(mph[x - prev]++))
                hor.insert(x-prev);
            if(!(mph[next - x]++))
                hor.insert(next - x);
            horp.insert(x);
        }else{
            set<int>::iterator it = verp.lower_bound(x);
            int next = *it;
            --it;
            int prev = *it;
            if(!(--mpv[next-prev]))
                ver.erase(next-prev);
            if(!(mpv[x - prev]++))
                ver.insert(x-prev);
            if(!(mpv[next - x]++))
                ver.insert(next - x);
            verp.insert(x);
        }
        int bestv = *(ver.begin());
        int besth = *(hor.begin());
        printf("%I64d\n",(long long)bestv * besth);
    }
    return 0;
}