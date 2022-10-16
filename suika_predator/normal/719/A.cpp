#include<iostream>
using namespace std;
int n,x,prev;
int main()
{
    cin>>n;
    if(n==1){cin>>x;if(x==15)cout<<"DOWN"<<endl;else if(x==0)cout<<"UP"<<endl;else cout<<-1<<endl;return 0;}
    for(int i=1;i<=n-2;i++)cin>>x;
    cin>>prev>>x;
    if(x==15||(x!=0&&x<prev))cout<<"DOWN"<<endl;
    else cout<<"UP"<<endl;
    return 0;
}