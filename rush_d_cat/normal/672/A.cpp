#include<iostream>
using namespace std;
int main()
{
    int a[5000+2];
    int pos=0;
    for(int i=1;i<=500;i++){
        if(i<10) a[++pos]=i;
        else if(i<100)
        {
            a[++pos]=i/10;
            a[++pos]=i%10;
        }else{
            a[++pos]=i/100;
            a[++pos]=i/10%10;
            a[++pos]=i%10;
        }
    }
    int n;
    cin>>n;cout<<a[n]<<endl;
    return 0;
}