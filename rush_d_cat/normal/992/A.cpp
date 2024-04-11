#include <iostream>
#include <set>
using namespace std;
set<int> st;
int n,x;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x!=0) st.insert(x);
    }
    cout<<st.size()<<endl;
}