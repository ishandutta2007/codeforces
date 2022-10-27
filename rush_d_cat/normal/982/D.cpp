#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1000002;
map<int, vector<int> > v;
int n, a[N], p[N], sz[N];
multiset<int> st;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
int find(int x) {
    return p[x]==-1?x:p[x]=find(p[x]);
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        v[a[i]].push_back(i);
    }

    int bst=*max_element(a+1,a+1+n), mx=-1;

    bool fi = 1;
    for(auto x:v) {
        if (fi) {
            for(int i=1;i<=n;i++) {
                if(a[i] == x.first) {
                    sz[i]=1, p[i]=-1;
                }
            }

            for (int i=1;i<=n;i++) {
                if (i>=2 && a[i-1]==x.first && a[i]==x.first) {
                    sz[find(i-1)] ++;
                    p[i] = find(i-1);
                }
            }

            for (int i=1;i<=n;i++) {
                if (a[i] == x.first && find(i) == i) {
                    st.insert(sz[i]);
                }
            }

            fi = 0; 

            if ( (*st.begin() == *st.rbegin()) ) {
                if ((int)st.size() > mx) {
                    mx = st.size();
                    bst = x.first;
                }
            }

            continue;
        } 

        for(int i=0;i<x.second.size();i++) {
            int pos = x.second[i];
            int lim = x.first;
            //printf("pos = %d\n", pos);
            if (pos>=2 && a[pos-1]<=lim) {
                
                st.erase(st.find(sz[find(pos-1)]));
                //printf("era %d\n", sz[find(pos-1)]);
                p[pos] = find(pos-1);
                sz[find(pos-1)] ++;
                st.insert(sz[find(pos-1)]); 
                //printf("ins %d\n", sz[find(pos-1)]);

            } else if(pos<n && a[pos+1]<=lim) {
                
                st.erase(st.find(sz[find(pos+1)]));
                //printf("era %d\n", sz[find(pos+1)]);
                p[pos] = find(pos+1);
                sz[find(pos+1)] ++;
                //printf("ins %d\n", sz[find(pos+1)]);
                st.insert(sz[find(pos+1)]); 
            
            } else {
            
                p[pos] = -1, sz[pos]=1;
                st.insert(1);
                //printf("ins %d\n", 1);
            }

            if ( (*st.begin() == *st.rbegin()) ) {
                //printf("!siiiiiz %d %d %d\n", st.size(),x.first, mx);
                if ((int)st.size() > mx) {
                    mx = st.size();
                    bst = x.first;
                    //printf("bst = %d\n", bst);
                }
            }
        }
    }

    printf("%d\n", bst+1);

}