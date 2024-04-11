#include<iostream>

using namespace std;

#define MAX 500005

bool res[15][2];
char commands[MAX];
int num[MAX];

int Xor,Or,And;

int main ()
{
    int n,i,j,st=1,j2;
    bool b,b2,BB;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>commands[i]>>num[i];
    }


    for(i=0;i<=9;i++)
    {
        for(j2=0;j2<=1;j2++)
        {
            b=j2;
            for(j=0;j<n;j++)
            {
                b2=(num[j]>>i)&1;

                if(commands[j]=='|')
                {
                    b=b2|b;
                }
                else
                {
                    if(commands[j]=='&')
                    {
                        b=b2&b;
                    }
                    else
                    {
                        b=b2^b;
                    }
                }
            }

            if(j2==0)BB=b;
            else
            {
                if(BB==0 && b==0)
                {
                    Or+=st;
                    Xor+=st;
                }
                if(BB==1 && b==0)
                {
                    Xor+=st;
                }
                if(BB==1 && b==1)
                {
                    Or+=st;
                }
            }
        }
        st*=2;
    }

    cout<<"2"<<endl;
    cout<<"| "<<Or<<endl;
    cout<<"^ "<<Xor<<endl;

    return 0;
}