#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_N 3000

int N;
int DP[MAX_N+1][4];
int arr[MAX_N+1];
int ans=-1;


int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<=N; i++)
    {
        cin>>DP[i][1];
        for(int j=1; j<i; j++)
        {
            if(arr[i]>arr[j] && (DP[i][2]==0 || DP[i][2]>DP[i][1]+DP[j][1]))
            {
                DP[i][2]=DP[i][1]+DP[j][1];
            }
            if(arr[i]>arr[j] && DP[j][2]!=0 && (DP[i][3]==0 || DP[i][3]>DP[i][1]+DP[j][2]))
            {
                DP[i][3]=DP[i][1]+DP[j][2];
                if(ans==-1 || ans>DP[i][3])
                {
                    ans=DP[i][3];
                }
            }
        }
    }
    cout<<ans;
    return 0;
}