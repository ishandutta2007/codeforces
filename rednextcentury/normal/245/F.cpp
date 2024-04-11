#include<bits/stdc++.h>

using namespace std;
int mon[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
__inline int calc(int month,int day,int hour,int minute,int second)
{
    return (mon[month-1]+day)*24*60*60+hour*60*60+minute*60+second;
}
void print(int year,int month,int day,int hour,int minute,int second)
{
    printf("%d-",year);
    if (month<10)
        printf("0");
    printf("%d-",month);
    if (day<10)
        printf("0");
    printf("%d ",day);
    if (hour<10)
        printf("0");
    printf("%d:",hour);
    if (minute<10)
        printf("0");
    printf("%d:",minute);
    if (second<10)
        printf("0");
    printf("%d\n",second);
}
int main()
{
    for (int i=1;i<13;i++)
        mon[i]+=mon[i-1];
    int n,m;
    cin>>n>>m;
    int year,month,day,hour,minute,second;
    int sum=0;
    int last=0;
    multiset<int> st;
    while(scanf("%d-%d-%d %d:%d:%d: ",&year,&month,&day,&hour,&minute,&second)!=EOF)
    {
        string s;
        getline(cin,s);
        int cur=calc(month,day,hour,minute,second);

        st.insert(cur);
        multiset<int>::iterator it=st.begin();
        int t=cur-n;
        while(!st.empty() && *it<=t)
            sum--,st.erase(it),it=st.begin();
        sum++;
        if (sum>=m)
        {
            print(year,month,day,hour,minute,second);
            return 0;
        }
    }
    cout<<-1<<endl;
}