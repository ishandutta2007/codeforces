#include <cstdio>
#include <set>
using namespace std;
int ans[2][100005];
int a[100005];
multiset<int> st;
multiset<int>::iterator it;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int ans_num=0,ans_len;
    int start=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        st.insert(a[i]);
        it=st.end();
        it--;
        while(*it-*(st.begin())>k){
            st.erase(st.find(a[start++]));
            it=st.end();
            it--;
        }
        if(st.size()>ans_num){
            ans_num=st.size();
            ans_len=0;
        }
        if(st.size()==ans_num){
            ans_len++;
            ans[0][ans_len]=start;
            ans[1][ans_len]=i;
        }
    }
    printf("%d %d\n",ans_num,ans_len);
    for(int i=1;i<=ans_len;i++){
        printf("%d %d\n",ans[0][i],ans[1][i]);
    }
    return 0;
}