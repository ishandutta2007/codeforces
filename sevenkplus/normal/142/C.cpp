#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string a[100][100];
int main()
{
a[1][1]=".";
a[1][2]="..";
a[1][3]="...";
a[1][4]="....";
a[1][5]=".....";
a[1][6]="......";
a[1][7]=".......";
a[1][8]="........";
a[1][9]=".........";
a[2][2]="....";
a[2][3]="......";
a[2][4]="........";
a[2][5]="..........";
a[2][6]="............";
a[2][7]="..............";
a[2][8]="................";
a[2][9]="..................";
a[3][3]="A..AAAA..";
a[3][4]="A...AAA.A...";
a[3][5]="A.BBBAAAB.A..B.";
a[3][6]="A.BBB.AAAB..A..B..";
a[3][7]="A.BBB.CAAABCCCA..B..C";
a[3][8]="A.BBB.C.AAABCCC.A..B..C.";
a[3][9]="A.BBBCDDDAAAB.C.D.A..BCCCD.";
a[4][4]="A...AAABABBB...B";
a[4][5]="A.BBBAAAB.A..B......";
a[4][6]="A.BBB.AAABC.A..BC....CCC";
a[4][7]="A..BBB.AAACBD.ACCCBD....CDDD";
a[4][8]="A.BBBC..AAABDCCCA..BDC.....DDD..";
a[4][9]="A.BBBC...AAABDCCCEA..BDCEEE...DDD..E";
a[5][5]="A.BBBAAAB.AC.BD.CDDDCCC.D";
a[5][6]="A.BBB.AAABC.A.DBC.DDDCCC..D...";
a[5][7]="A.BBB.CAAABCCCA.DB.ECDDDEEE...D..E.";
a[5][8]="A.BBB.C.AAABCCC.A.DBE.CFDDD.EFFF..DEEE.F";
a[5][9]="A.BBB.CCCAAABDDDC.A.EBFDGC.EEE.FDGGG..EFFFG..";
a[6][6]="A.BBB.AAAB..A.CB...DCCCE.DCEEEDDD..E";
a[6][7]="A.BBB.CAAABCCCA.DBE.CDDDFEEE..DFE....FFF..";
a[6][8]="A.BBB.C.AAABCCC.A.DBE.C.DDDFEEEG..DFEGGG..FFF..G";
a[6][9]="A.BBBCDDDAAAB.C.D.A.EBCCCDFEEEG.HFFF..EG.HHHF..GGGH...";
a[7][7]="A.BBB.CAAABCCCA.DB.ECDDDEEE.F.DG.EHFFFGHHHF.GGG.H";
a[7][8]="A.BBB..CAAABDCCCA.EBDDDCEEEFDGGG.HEF.IG..HFFFIG.HHH.III.";
a[7][9]="A.BBBCDDDAAAB.C.D.A.EBCCCDFEEEG..FFF.HEGIIIJF.HGGGI.J.HHH..IJJJ";
a[8][8]="A.BBB.C.AAABCCC.AD.BEFC..DEEEFFFDDDGEF.HIGGGJHHHIIIGJ..HI..JJJ..";
a[8][9]="A.BBBC...AAABDCCCEA.FBDCEEEFFFDDDG.EH.FIIIGGGHHHJIKG.LHJJJIKLLL...JKKK.L";
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==9&&m==9){puts("13\nA.BBBCDDD\nAAAB.C.D.\nA.FBCCCDE\nFFFGGGEEE\nI.FHGJJJE\nIIIHG.JK.\nILHHHMJK.\n.L...MKKK\nLLL.MMM..");return 0;}
    string S;
    if(n<=m)S=a[n][m];else S=a[m][n];
    int T=0;
    for(int i=0;i<n*m;i++)if(S[i]!='.')T=max(T,S[i]-'A'+1);
    printf("%d\n",T);
    if(n<=m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)putchar(S[i*m+j]);
            puts("");
        }
    }else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)putchar(S[j*n+i]);
            puts("");
        }
    }
    return 0;
}