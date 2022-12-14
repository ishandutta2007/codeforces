#include <iostream>
#include <string>

using namespace std;
int N;
string str[100];
int M;
string a[100]={"Power", "Time", "Space", "Soul", "Reality", "Mind"};
char c[100]={'p', 'g', 'b', 'o', 'r', 'y'};



int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>str[i];
    }
    cout<<6-N<<endl;
    for(int i=1; i<=6; i++)
    {
        bool b=false;
        for(int j=1; j<=N; j++)
        {
            if(str[j].at(0)==c[i-1])
            {
                b=true;
                break;
            }
        }
        if(!b)
        {
            cout<<a[i-1]<<endl;
        }
    }
    return 0;
}