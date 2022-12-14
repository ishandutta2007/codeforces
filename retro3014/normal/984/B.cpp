#include <iostream>
#include <string>

using namespace std;
#define MAX_N 100

int N, M;
string str[MAX_N+1];
int dx[8]={0, 0, -1, 1, 1, 1, -1, -1}, dy[8]={1, -1, 0, 0, 1, -1, 1, -1};


void prob()
{
    cout<<"NO";
}

int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>str[i];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(str[i].at(j)!='*')
            {
                int cnt=0;
                for(int k=0; k<8; k++)
                {
                    if(i+dx[k]>=0 && i+dx[k]<N && j+dy[k]>=0 && j+dy[k]<M && str[i+dx[k]].at(j+dy[k])=='*')
                    {
                        cnt++;
                    }
                }
                if(cnt==0)
                {
                    if(str[i].at(j)!='.')
                    {
                        prob();
                        return 0;
                    }
                }
                else
                {
                    if(str[i].at(j)!='0'+cnt)
                    {
                        prob();
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"YES";
    return 0;
}