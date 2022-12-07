#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <limits.h>
#define MOD 1000000009
#define INF INT_MAX
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

char qur[8];

int cnte,cntt,cntf;
bool chke[256],chkt[256],chkf[256];
char e[256][111],t[256][111],f[256][111];
int aaa[256][256];
vector<int> ve,vt,vf;

char tmp[111];

char ans[256][111];

int main(){
    int n,num;

    strcpy(f[15],"x"); vf.push_back(15); chkf[15]=1;
    strcpy(f[51],"y"); vf.push_back(51); chkf[51]=1;
    strcpy(f[85],"z"); vf.push_back(85); chkf[85]=1;
    cntf=3;

    bool neww=1;
    while(neww){
        neww=0;
/*
        printf("%d %d %d\n",ve.size(),vt.size(),vf.size());
        for(int i=0;i<ve.size();i++) printf("%d ",ve[i]);
        printf("\n");
        for(int i=0;i<vt.size();i++) printf("%d ",vt[i]);
        printf("\n");
        for(int i=0;i<vf.size();i++) printf("%d ",vf[i]);
        printf("\n\n\n");
*/
        for(int i=0;i<vf.size();i++){
            if(!chkt[vf[i]] || strlen(t[vf[i]])>strlen(f[vf[i]])
               || (strlen(t[vf[i]])==strlen(f[vf[i]]) && strcmp(t[vf[i]],f[vf[i]])>0)){
                strcpy(t[vf[i]],f[vf[i]]);
                if(!chkt[vf[i]]){
                    vt.push_back(vf[i]);
                    chkt[vf[i]]=1;
                    cntt++;
                }
                neww=1;
            }
        }

        for(int i=0;i<vt.size();i++){
            if(!chke[vt[i]] || strlen(e[vt[i]])>strlen(t[vt[i]])
               || (strlen(e[vt[i]])==strlen(t[vt[i]]) && strcmp(e[vt[i]],t[vt[i]])>0)){
                strcpy(e[vt[i]],t[vt[i]]);
                if(!chke[vt[i]]){
                    ve.push_back(vt[i]);
                    chke[vt[i]]=1;
                    cnte++;
                }
                neww=1;
            }
        }

        for(int i=0;i<vf.size();i++){
            strcpy(tmp,"!");
            strcat(tmp,f[vf[i]]);
            if(!chkf[255-vf[i]] || strlen(f[255-vf[i]])>strlen(tmp)
               || (strlen(f[255-vf[i]])==strlen(tmp) && strcmp(f[255-vf[i]],tmp)>0)){
                strcpy(f[255-vf[i]],tmp);
                if(!chkf[255-vf[i]]){
                    vf.push_back(255-vf[i]);
                    chkf[255-vf[i]]=1;
                    cntf++;
                }
                neww=1;
            }
        }

        for(int i=0;i<ve.size();i++){
            strcpy(tmp,"(");
            strcat(tmp,e[ve[i]]);
            strcat(tmp,")");
            if(!chkf[ve[i]] || strlen(f[ve[i]])>strlen(tmp)
               || (strlen(f[ve[i]])==strlen(tmp) && strcmp(f[ve[i]],tmp)>0)){
                strcpy(f[ve[i]],tmp);
                if(!chkf[ve[i]]){
                    vf.push_back(ve[i]);
                    chkf[ve[i]]=1;
                    cntf++;
                }
                neww=1;
            }
        }

        for(int i=0;i<ve.size();i++){
            for(int j=0;j<vt.size();j++){
                strcpy(tmp,e[ve[i]]);
                strcat(tmp,"|");
                strcat(tmp,t[vt[j]]);
                if(!chke[ve[i]|vt[j]] || strlen(e[ve[i]|vt[j]])>strlen(tmp)
                   || (strlen(e[ve[i]|vt[j]])==strlen(tmp) && strcmp(e[ve[i]|vt[j]],tmp)>0)){
                    strcpy(e[ve[i]|vt[j]],tmp);
                    if(!chke[ve[i]|vt[j]]){
                        ve.push_back(ve[i]|vt[j]);
                        chke[ve[i]|vt[j]]=1;
                        cnte++;
                    }
                    neww=1;
                }
            }
        }

        for(int i=0;i<vt.size();i++){
            for(int j=0;j<vf.size();j++){
                strcpy(tmp,t[vt[i]]);
                strcat(tmp,"&");
                strcat(tmp,f[vf[j]]);
                if(!chkt[vt[i]&vf[j]] || strlen(t[vt[i]&vf[j]])>strlen(tmp)
                   || (strlen(t[vt[i]&vf[j]])==strlen(tmp) && strcmp(t[vt[i]&vf[j]],tmp)>0)){

                    strcpy(t[vt[i]&vf[j]],tmp);
                    if(!chkt[vt[i]&vf[j]]){
                        vt.push_back(vt[i]&vf[j]);
                        chkt[vt[i]&vf[j]]=1;
                        cntt++;
                    }
                    neww=1;
                }
            }
        }
    }

    for(int i=0;i<256;i++){
        int lene=strlen(e[i]);
        int lent=strlen(t[i]);
        int lenf=strlen(f[i]);

        strcpy(ans[i],e[i]);
        if(lene<lent || (lene==lent && strcmp(e[i],t[i])<0)){
            if(lene<lenf || (lene==lenf && strcmp(e[i],f[i])<0)) strcpy(ans[i],e[i]);
            else strcpy(ans[i],f[i]);
        }
        else{
            if(lent<lenf || (lent==lenf && strcmp(t[i],f[i])<0)) strcpy(ans[i],t[i]);
            else strcpy(ans[i],f[i]);
        }
    }
    for(int i=0; i<1000; i++)
    {
        for(int j=0; j<10000; j++)
        {
            aaa[i%256][j%256]+=5;
        }
    }
    scanf("%d",&n);
    while(n--){
        scanf("%s",qur);

        num=0;
        for(int i=0;i<8;i++){
            if(qur[7-i]=='1') num+=(1<<i);
        }

        printf("%s\n",ans[num]);
    }

    return 0;
}