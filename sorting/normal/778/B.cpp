#include<iostream>
#include<unordered_map>

using namespace std;

#define base 257
#define MOD 1000000007

struct pairHash
{
    int operator()(const pair<string,int> p)const
    {
        int i;
        int res=7;

        for(i=0;i<p.first.size();i++)
        {
            res=(long long)(res*base+p.first[i])%MOD;
        }
        res=(long long)(res*base+p.second)%MOD;

        return res;
    }
};

unordered_map<pair<string,int>,string,pairHash> Map;
int sum[1001][2];

int main ()
{
    int n,m,i,j;
    string s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11;
    int b,b2;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>s1>>s2>>s3;

        s6.clear();
        s7.clear();
        //s8.clear();
        //s9.clear();
        //s10.clear();
        //s11.cl

        if(s3[0]=='0' || s3[0]=='1')
        {
            //cout<<s3<<endl;
            //s6=Map[make_pair(s1,0)];
            //s7=Map[make_pair(s1,1)];
            for(j=0;j<m;j++)
            {
                b=(int)s3[j]-'0';
                //cout<<b<<" "<<s3[j]<<endl;
                s6+=(char)b;
                s7+=(char)b;
            }
        }
        else
        {
            cin>>s4>>s5;



            if(s3=="?" && s5=="?")
            {
                if(s4=="XOR")
                {
                    for(j=0;j<m;j++)
                    {
                        s6+=(char)0;
                        s7+=(char)0;
                    }
                }
                else
                {
                    for(j=0;j<m;j++)
                    {
                        s6+=(char)0;
                        s7+=(char)1;
                    }
                }
            }
            else
            {
                if(s3=="?")swap(s3,s5);

                 s8=Map[make_pair(s3,0)];
                s9=Map[make_pair(s3,1)];
                s10=Map[make_pair(s5,0)];
                s11=Map[make_pair(s5,1)];

                if(s5=="?")
                {

                    if(s4=="XOR")
                    {
                        for(j=0;j<m;j++)
                        {
                            //b=(int)s3[j]-'0';
                            s6+=(int)0^s8[j];
                            //cout<<(int)s8[j]<<endl;
                            s7+=(int)1^s9[j];
                        }
                    }
                    else
                    {
                        if(s4=="OR")
                        {
                            for(j=0;j<m;j++)
                            {
                                //b=(int)s3[j]-'0';
                                s6+=(int)0|s8[j];
                                s7+=(int)1|s9[j];
                            }
                        }
                        else
                        {
                            for(j=0;j<m;j++)
                            {
                                //b=(int)s3[j]-'0';
                                s6+=(int)0&s8[j];
                                s7+=(int)1&s9[j];
                            }
                        }
                    }
                }
                else
                {
                    if(s4=="XOR")
                    {
                        for(j=0;j<m;j++)
                        {
                            //b=(int)s3[j]-'0';
                            //b2=(int)s5[j]-'0';
                            s6+=(int)s10[j]^s8[j];
                            s7+=(int)s11[j]^s9[j];
                        }
                    }
                    else
                    {
                        if(s4=="OR")
                        {
                            for(j=0;j<m;j++)
                            {
                                //b=(int)s3[j]-'0';
                                //b2=(int)s5[j]-'0';
                                s6+=(int)s10[j]|s8[j];
                                s7+=(int)s11[j]|s9[j];
                            }
                        }
                        else
                        {
                            for(j=0;j<m;j++)
                            {
                                //b=(int)s3[j]-'0';
                                //b2=(int)s5[j]-'0';
                                s6+=(int)s10[j]&s8[j];
                                s7+=(int)s11[j]&s9[j];
                            }
                        }
                    }
                }
            }
        }
        for(j=0;j<m;j++)
        {
            //cout<<Map[j][make_pair(s1,0)]<<" "<<Map[j][make_pair(s1,1)]<<" "<<j<<endl;
            sum[j][0]+=s6[j];
            sum[j][1]+=s7[j];
            //cout<<(int)s6[j]<<" "<<(int)s7[j]<<endl;
        }
        Map[make_pair(s1,0)]=s6;
        Map[make_pair(s1,1)]=s7;
    }

    for(i=0;i<m;i++)
    {
        if(sum[i][0]<=sum[i][1])cout<<"0";
        else cout<<"1";

        //cout<<sum[i][0]<<" "<<sum[i][1]<<endl;
    }

    cout<<"\n";

    for(i=0;i<m;i++)
    {
        if(sum[i][0]>=sum[i][1])cout<<"0";
        else cout<<"1";
    }

    cout<<"\n";

    return 0;
}