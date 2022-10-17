#include <cstdio>
#include <queue>
using namespace std;
char s[100005];
int num[30];
priority_queue<int> q;
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        num[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(num[i]>0){
            q.push(num[i]);
        }
    }
    int x,y;
    while(q.size()>1&&q.top()>1){
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        x+=y;
        q.push(x);
    }
    if(q.size()>1){
        puts("No");
    }
    else{
        puts("Yes");
    }
    return 0;
}