#include <iostream>

using namespace std;

long long int number(long long int n, long long int k)
{
    long long int num=0;
    while(n!=0){
        if(n > k) {num+=k; n-=k;}
        else {num+=n; n=0;}
        n-=(n/10);
    }
    return num;
}

int main()
{
    long long int n,ans=0;
    cin >> n;
    ans = n/20+1;

    for(long long int i=n/10;i>0;i=i/10){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    //cout << number(12345678901234567,1) << endl;
    long long int temp1;
    if(ans >= 10) temp1 = ans /10;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 20) temp1 = ans /20;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 30) temp1 = ans /30;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 40) temp1 = ans /40;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 50) temp1 = ans /50;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 60) temp1 = ans /60;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 70) temp1 = ans /70;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 80) temp1 = ans /80;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 200) temp1 = ans /200;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 500) temp1 = ans /500;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 1000) temp1 = ans /1000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 2000) temp1 = ans /2000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 5000) temp1 = ans /5000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 10000) temp1 = ans /10000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 50000) temp1 = ans /50000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 1000000) temp1 = ans /1000000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 10000000) temp1 = ans /10000000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 100000000) temp1 = ans /100000000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 1000000000) temp1 = ans /1000000000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    if(ans >= 10000000000) temp1 = ans /10000000000;
    else temp1 =1;
    for(long long int i=ans;i>0;i-=temp1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    for(long long int i=ans;i>0;i-=1){
    if(number(n,i) < n/2 && n%2 == 0) break;
    else if(number(n,i) < (n+1)/2 && n%2 == 1) break;
    ans = i;
    }
    cout << ans << endl;
    return 0;
}