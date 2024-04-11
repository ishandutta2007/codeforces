#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int cnt[200005];
int nums[200005];
int unfind[200005];
int n;
bool put[200005];

int main() {
    memset(cnt,0,sizeof(cnt));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) put[i] = false;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        cnt[nums[i]] ++;
    }
    int unlen = 0;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) {
            unfind[unlen++] = i;
        }
    }
    printf("%d\n",unlen);
    sort(unfind,unfind+unlen);
    int pos = 0;
    for(int i = 1; i <= n; i++) {
    	//if(i == 1) printf("cnt[nums[i]] = %d ", nums[i]);
        if(cnt[nums[i]] >= 1) {
            if(!put[nums[i]]) {
            	if(cnt[nums[i]] == 1){
            		printf("%d ", nums[i]);
                    cnt[nums[i]] --;
                    put[nums[i]] = true;
				}
                else if(pos < unlen && nums[i] > unfind[pos]) {
                    printf("%d ", unfind[pos++]);
                    cnt[nums[i]] --;
                } else {
                    printf("%d ", nums[i]);
                    cnt[nums[i]] --;
                    put[nums[i]] = true;
                }
            }
            else{
            	printf("%d ", unfind[pos++]);
            	cnt[nums[i]] --;
			}
        }
    }

}