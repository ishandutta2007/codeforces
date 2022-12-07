#include <iostream>
#include <fstream>
using namespace std;
int T, U, R, D, L, N;
bool flag;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N>>U>>R>>D>>L;
        flag = false;
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                for(int l=0; l<2; l++)
                {
                    for(int m=0; m<2; m++)
                    {
                        if(j+k <= U && U <= N-2+j+k)
                        {
                            if(k+l <= R && R <= N-2+k+l)
                            {
                                if(l+m <= D && D <= N-2+l+m)
                                {
                                    if(m+j <= L && L <= N-2+m+j)
                                    {
                                        flag = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<(flag ? "YES": "NO")<<endl;
    }
}