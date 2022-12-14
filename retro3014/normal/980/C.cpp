#include <iostream>
#include <vector>

using namespace std;
#define MAX_N 100000

int N, M;
int arr[MAX_N+1];
int chk[MAX_N+1];

int main()
{
    cin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        cin>>arr[i];
        int idx=arr[i];
        int t=M-1;
        if(chk[idx]!=0)
        {
            while(chk[idx]!=1)
            {
                idx--;
            }
        }
        else
        {
            while(chk[idx]==0 && idx>=0 && t>0)
            {
                t--;
                chk[idx]=1;
                if(idx==0 || chk[idx-1]!=0)
                {
                    if(idx!=0 && arr[i]-(idx-chk[idx-1])+1<=M)
                    {
                        idx=idx-chk[idx-1];
                    }
                    chk[idx]=1;
                    break;
                }
                idx--;
            }
        }
        for(int j=idx; j<=arr[i]; j++)
        {
            chk[j]=j-idx+1;
        }
        arr[i]=idx;
        cout<<arr[i]<<" ";
    }
    
    return 0;
}