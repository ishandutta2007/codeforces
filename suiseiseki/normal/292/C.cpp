#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int A[105],vis[105],n;
int S[105],pos[105],w[105],len;
char line[105];
vector<string> ans;
void solve(){
    int s1,s2,s3,s4;
    for(int a=1;a<=3;a++){
        s1=0;
        for(int i=1;i<=a;i++){
        	s1=(s1<<1)+(s1<<3)+S[i];
		}
        if(s1>255||(a>1&&!S[1])){
        	continue;
		}
        for(int b=1;b<=3;b++){
            s2=0;
            for(int i=1;i<=b;i++){
            	s2=(s2<<1)+(s2<<3)+S[a+i];
			}
            if(s2>255||(b>1&&!S[a+1])){
            	continue;
			}
            for(int c=1;c<=3;c++){
                s3=0;
                for(int i=1;i<=c;i++){
                	s3=(s3<<1)+(s3<<3)+S[a+b+i];
				}
                if(s3>255||a+b+c>=len||(c>1&&!S[a+b+1])){
                	continue;
				}
                s4=0;
                for(int i=1;i<=len-a-b-c;i++){
                	s4=(s4<<1)+(s4<<3)+S[a+b+c+i];
				}
                if(s4>255||(len-a-b-c>1&&!S[a+b+c+1])){
                	continue;
				}
                sprintf(line,"%d.%d.%d.%d",s1,s2,s3,s4);
                ans.push_back(line);
            }
        }
    }
}
void DFS1(int p){
    if(p>(len+1)>>1){
        int cnt=0;
        for(int i=1;i<=n;i++){
        	cnt+=vis[i]>0;
		}
        if(cnt!=n){
        	return;
		}
        solve();
        return;
    }
    for(int i=1;i<=n;i++){
        vis[i]++;
        S[p]=S[len-p+1]=A[i];
        DFS1(p+1);
        vis[i]--;
    }
}
int main(){
	scanf("%d",&n);
    ans.clear();
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for(len=4;len<=12;len++){
        DFS1(1);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++){
    	cout<<ans[i]<<endl;
    }
    return 0;
}