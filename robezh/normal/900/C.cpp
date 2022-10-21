#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
int num[100050];
int cumu[100050];
bool up[100050];
int maxi, smaxi;
int maxD = -1;
int res = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    fill(cumu, cumu+n, 0);
    fill(up, up+n, 0);
    maxi = 0, smaxi = -1;
    int maxval = 0;
    bool good = true;
    for(int i = 0; i < n; i++) {
        if(num[i] > maxval) {
            maxval = num[i], up[i] = true;
        }else{
        	good = false;
		}
    }
    if(good) return !printf("1\n");
    for(int i = 1; i < n; i++) {
        //printf("num[i:%d] = %d num[maxi:%d] = %d num[smaxi:%d] = %d\n",i, num[i],maxi, num[maxi], smaxi, num[smaxi]);
        if(num[i] > num[maxi]) {
            smaxi = maxi;
            maxi = i;
        } else if(smaxi == -1 || num[i] > num[smaxi]) smaxi = i, cumu[maxi] ++;
    }
    for(int i = 0; i < n; i++) if(cumu[i] > 0) cumu[i] --;
    for(int i = 0; i < n; i++) {
        if(cumu[i] == 0 && up[i]) continue;
        if(cumu[i] > maxD) maxD = cumu[i], res = num[i];
        else if(cumu[i] == maxD) res = (res < num[i] ? res : num[i]);
    }
    cout << res;
}