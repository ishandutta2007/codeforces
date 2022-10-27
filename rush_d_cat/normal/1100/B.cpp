#include <iostream>
#include <set>
using namespace std;
const int N=100000+10;
int n,m,a[N];
multiset<int> st; int c[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        st.insert(0);

    int low=0;
    for(int i=1;i<=m;i++){
        st.erase(st.find(c[a[i]]));
        c[a[i]] ++;
        st.insert(c[a[i]]);
        if((*st.begin()) > low)
            low ++, printf("1");
        else
            printf("0");
    }
}