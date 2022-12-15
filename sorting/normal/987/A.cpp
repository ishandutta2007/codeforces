#include<iostream>

using namespace std;

string s[6]={ "purple", "green", "blue", "orange", "red", "yellow"};
string s2[6]={"Power", "Time", "Space", "Soul", "Reality", "Mind"};
bool b[6];

int main ()
{
    int n,i,j;

    cin>>n;

    string m;

    for(i=0;i<n;i++)
    {
        cin>>m;
        for(j=0;j<6;j++)
            if(s[j]==m)
                b[j]=1;
    }

    cout<<6-n<<endl;

    for(i=0;i<6;i++)
        if(!b[i])
            cout<<s2[i]<<endl;

    return 0;
}