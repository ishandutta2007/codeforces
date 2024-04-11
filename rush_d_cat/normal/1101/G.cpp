#include <iostream>
using namespace std;
int n;

int p[62];
void insert(int x) {
    for (int i = 31; i >= 0; i --) if ((x >> i) & 1) {
        if ( p[i] ) {
            x ^= p[i];
        } else {
            p[i] = x; 
            break;
        }
    }
} 

int main(){
    scanf("%d",&n);
    int s=0;
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        s^=x;
        insert(s);
    }
    if(s==0) {
        printf("-1\n");return 0;
    }
    int ans=0;
    for(int i=0;i<60;i++)if(p[i])ans++;
    cout<<ans<<endl;
}