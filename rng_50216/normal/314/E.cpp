#include <stdio.h>
#include<iostream>

int n,m;
char s[111111];
unsigned int temp1[222222];
unsigned int  *f = temp1 + 111111;

void addShiftedLeft(int n) {
  --f;
  f[0] = 0;
}

void addShiftedLeftAndShiftedRight(int n, int k) {
  f[-1] = 0;
  for (int i = -(k & 1); i < n-1; i += 2) {
    f[i] += f[i+2];
  }
  --f;
}

int min(int a, int b) {
  return a < b? a: b;
}

int main(){
    scanf("%d",&n);
    scanf("%s",s);
    f[0] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        cnt++;
        addShiftedLeftAndShiftedRight(min(i+10, n-i+10), i);
      } else {
        cnt--;
        addShiftedLeft(min(i+10, n-i+10));
      }
    }
    cnt/=2; 
    unsigned int answer = f[0];
    while(cnt-->0) answer *= 25;
   std:: cout<<answer<<std::endl;
}