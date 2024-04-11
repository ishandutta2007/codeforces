#include <iostream>
#include <fstream>
using namespace std;
int judge(int r)
{
    if(r==0)
    {
        return 0;
    }
    else
    {
        return judge(r/10)+r%10;
    }
}
int main()
{
    int K;
    cin>>K;
    for(int i=0; ; i++)
    {
        if(judge(i)==10)
        {
            --K;
        }
        if(K==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}