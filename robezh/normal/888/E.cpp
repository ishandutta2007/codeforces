#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int n,m;
int num[40];
int left[20];
int right[20];
int leftcomb[300000];
int rightcomb[150000];
int leftsize = 0;
int rightsize = 0;

int main() {
    scanf("%d%d",&n, &m);
    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        num[i] = k % m;
    }
    int mid = (n - 1) / 2;
    for(int i = 0; i <= mid; i++) {
        int pos = leftsize;
        for(int j = 0; j < leftsize; j++) {
            leftcomb[pos++] = (leftcomb[j] + num[i]) % m;
        }
        leftsize = pos;
        leftcomb[leftsize++] = num[i];
    }
    for(int i = mid + 1; i < n; i++) {
        int pos = rightsize;
        for(int j = 0; j < rightsize; j++) {
            rightcomb[pos++] = (rightcomb[j] + num[i]) % m;
        }
        rightsize = pos;
        rightcomb[rightsize++] = num[i];
    }
//    for(int i = 0; i < leftsize; i++) printf("%d ", leftcomb[i]);
//    printf("\n");
//    for(int i = 0; i < rightsize; i++) printf("%d ", rightcomb[i]);
//    printf("\n");

    int ans = 0;
    for(int i = 0; i < rightsize; i++) ans = max(ans, rightcomb[i]);
    for(int i = 0; i < leftsize; i++) ans = max(ans, leftcomb[i]);
    sort(rightcomb, rightcomb + rightsize);
    sort(leftcomb, leftcomb + leftsize);

//    for(int i = 0; i < leftsize; i++) printf("%d ", leftcomb[i]);
//    printf("\n");
//    for(int i = 0; i < rightsize; i++) printf("%d ", rightcomb[i]);
//    printf("\n");
    int leftpos = 0;
    int rightpos = rightsize - 1;
    while(leftpos < leftsize && rightpos >= 0) {
        int comb = rightcomb[rightpos] + leftcomb[leftpos];
        if(comb < m) {
            ans = max(ans, comb);
            leftpos ++;
        } else {
            rightpos--;
        }
    }
    cout << ans;
}