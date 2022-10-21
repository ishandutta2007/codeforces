#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;


int mindiff,maxlikes;
int exp[17];
int a[17][17];
int team[17];
int Diablo,Mephisto,Baal;


void bruteforce(int left);
void check();
void fillexp();
int findlike();

int main()
    {
    int n;
    int i;
    string p,t,q;
    int ind1;
    int ind2;
    cin>>n;
    for(i=0;i<n;i++)
        {
        cin>>p>>t>>q;
        if(p=="Anka")ind1=1;
        if(p=="Chapay")ind1=2;
        if(p=="Cleo")ind1=3;
        if(p=="Troll")ind1=4;
        if(p=="Dracul")ind1=5;
        if(p=="Snowy")ind1=6;
        if(p=="Hexadecimal")ind1=7;


        if(q=="Anka")ind2=1;
        if(q=="Chapay")ind2=2;
        if(q=="Cleo")ind2=3;
        if(q=="Troll")ind2=4;
        if(q=="Dracul")ind2=5;
        if(q=="Snowy")ind2=6;
        if(q=="Hexadecimal")ind2=7;
        ///cout<<ind1<<" " <<ind2<<"\n";
        a[ind1][ind2]=1;
        }
    cin>>Diablo>>Mephisto>>Baal;
    mindiff=1000000000;
    maxlikes=-1;
    bruteforce(1);
    cout<<mindiff<<" "<<maxlikes<<"\n";
    return 0;
    }


void bruteforce(int left)
    {
    int i;
    if(left==8){check();return ;}
    for(i=1;i<=3;i++)
        {
        team[left]=i;
        bruteforce(left+1);
        }
    }

void check()
    {
    fillexp();
    int ans=findlike();
    sort(exp+1,exp+8);
    int ans1=exp[7]-exp[1];
    int i;
    int br1=0;
    int br2=0;
    int br3=0;
    for(i=1;i<=7;i++)
        {
        if(team[i]==1)br1++;
        if(team[i]==2)br2++;
        if(team[i]==3)br3++;
        }
    if(br1==0 || br2==0 || br3==0)return ;
    if(ans1<mindiff)
        {
        mindiff=ans1;
        maxlikes=ans;

        }
    else if(ans1==mindiff)
        {
        if(maxlikes<ans)maxlikes=ans;
        /**
        if(ans==3)
        {
        for(i=1;i<=7;i++)
            {
            cout<<team[i]<<"\n";
            }
        }
        **/
        }

    }
void fillexp()
    {
    int i;
    int br1=0;
    int br2=0;
    int br3=0;
    for(i=1;i<=7;i++)
        {
        if(team[i]==1)br1++;
        if(team[i]==2)br2++;
        if(team[i]==3)br3++;
        }
    for(i=1;i<=7;i++)
        {
        if(team[i]==1)exp[i]=Diablo/br1;
        if(team[i]==2)exp[i]=Mephisto/br2;
        if(team[i]==3)exp[i]=Baal/br3;
        }
    }
int findlike()
    {
    int i,j;
    int ans=0;
    for(i=1;i<=7;i++)
        {
        for(j=1;j<=7;j++)
            {
            if(a[i][j]==1 && team[i]==team[j])ans++;
            }
        }
    return ans;
    }