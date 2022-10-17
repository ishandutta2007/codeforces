#include <cstdio>
#include <stack>
using namespace std;
stack<int> st;
bool inside[200005];
int a[200005],b[200005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        inside[a[i]]=1;
    }
    for(int i=n;i>0;i--){
        st.push(a[i]);
    }
    int ans;
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        if(!inside[b[i]]){
            printf("0 ");
        }
        else{
            ans=0;
            while(st.top()!=b[i]){
                ans++;
                inside[st.top()]=0;
                st.pop();
            }
            inside[st.top()]=0;
            ans++;
            st.pop();
            printf("%d ",ans);
        }
    }
    puts("");
    return 0;
}