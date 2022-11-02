var m,n:longint;
begin
readln(m,n);
if (m=1) and (n=1) then
begin
writeln(0);
writeln('.');
end;
if (m=1) and (n=2) then
begin
writeln(0);
writeln('..');
end;
if (m=1) and (n=3) then
begin
writeln(0);
writeln('...');
end;
if (m=1) and (n=4) then
begin
writeln(0);
writeln('....');
end;
if (m=1) and (n=5) then
begin
writeln(0);
writeln('.....');
end;
if (m=1) and (n=6) then
begin
writeln(0);
writeln('......');
end;
if (m=1) and (n=7) then
begin
writeln(0);
writeln('.......');
end;
if (m=1) and (n=8) then
begin
writeln(0);
writeln('........');
end;
if (m=1) and (n=9) then
begin
writeln(0);
writeln('.........');
end;
if (m=2) and (n=1) then
begin
writeln(0);
writeln('.');
writeln('.');
end;
if (m=2) and (n=2) then
begin
writeln(0);
writeln('..');
writeln('..');
end;
if (m=2) and (n=3) then
begin
writeln(0);
writeln('...');
writeln('...');
end;
if (m=2) and (n=4) then
begin
writeln(0);
writeln('....');
writeln('....');
end;
if (m=2) and (n=5) then
begin
writeln(0);
writeln('.....');
writeln('.....');
end;
if (m=2) and (n=6) then
begin
writeln(0);
writeln('......');
writeln('......');
end;
if (m=2) and (n=7) then
begin
writeln(0);
writeln('.......');
writeln('.......');
end;
if (m=2) and (n=8) then
begin
writeln(0);
writeln('........');
writeln('........');
end;
if (m=2) and (n=9) then
begin
writeln(0);
writeln('.........');
writeln('.........');
end;
if (m=3) and (n=1) then
begin
writeln(0);
writeln('.');
writeln('.');
writeln('.');
end;
if (m=3) and (n=2) then
begin
writeln(0);
writeln('..');
writeln('..');
writeln('..');
end;
if (m=3) and (n=3) then
begin
writeln(1);
writeln('AAA');
writeln('.A.');
writeln('.A.');
end;
if (m=3) and (n=4) then
begin
writeln(1);
writeln('AAA.');
writeln('.A..');
writeln('.A..');
end;
if (m=3) and (n=5) then
begin
writeln(2);
writeln('AAA.B');
writeln('.ABBB');
writeln('.A..B');
end;
if (m=3) and (n=6) then
begin
writeln(2);
writeln('AAABBB');
writeln('.A..B.');
writeln('.A..B.');
end;
if (m=3) and (n=7) then
begin
writeln(3);
writeln('AAACBBB');
writeln('.A.C.B.');
writeln('.ACCCB.');
end;
if (m=3) and (n=8) then
begin
writeln(3);
writeln('AAABBB.C');
writeln('.A..BCCC');
writeln('.A..B..C');
end;
if (m=3) and (n=9) then
begin
writeln(4);
writeln('AAADBBB.C');
writeln('.A.D.BCCC');
writeln('.ADDDB..C');
end;
if (m=4) and (n=1) then
begin
writeln(0);
writeln('.');
writeln('.');
writeln('.');
writeln('.');
end;
if (m=4) and (n=2) then
begin
writeln(0);
writeln('..');
writeln('..');
writeln('..');
writeln('..');
end;
if (m=4) and (n=3) then
begin
writeln(1);
writeln('AAA');
writeln('.A.');
writeln('.A.');
writeln('...');
end;
if (m=4) and (n=4) then
begin
writeln(2);
writeln('AAA.');
writeln('.AB.');
writeln('.AB.');
writeln('.BBB');
end;
if (m=4) and (n=5) then
begin
writeln(2);
writeln('AAA..');
writeln('.ABBB');
writeln('.A.B.');
writeln('...B.');
end;
if (m=4) and (n=6) then
begin
writeln(3);
writeln('AAABBB');
writeln('.AC.B.');
writeln('.AC.B.');
writeln('.CCC..');
end;
if (m=4) and (n=7) then
begin
writeln(4);
writeln('AAABBB.');
writeln('.AC.BD.');
writeln('.AC.BD.');
writeln('.CCCDDD');
end;
if (m=4) and (n=8) then
begin
writeln(4);
writeln('AAABBB..');
writeln('.AD.BCCC');
writeln('.AD.B.C.');
writeln('.DDD..C.');
end;
if (m=4) and (n=9) then
begin
writeln(5);
writeln('AAABBBCCC');
writeln('.AD.BE.C.');
writeln('.AD.BE.C.');
writeln('.DDDEEE..');
end;
if (m=5) and (n=1) then
begin
writeln(0);
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
end;
if (m=5) and (n=2) then
begin
writeln(0);
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
end;
if (m=5) and (n=3) then
begin
writeln(2);
writeln('AAA');
writeln('.A.');
writeln('BA.');
writeln('BBB');
writeln('B..');
end;
if (m=5) and (n=4) then
begin
writeln(2);
writeln('AAA.');
writeln('.A..');
writeln('BA..');
writeln('BBB.');
writeln('B...');
end;
if (m=5) and (n=5) then
begin
writeln(4);
writeln('AAA.B');
writeln('.ABBB');
writeln('CA.DB');
writeln('CCCD.');
writeln('C.DDD');
end;
if (m=5) and (n=6) then
begin
writeln(4);
writeln('AAABBB');
writeln('.A..B.');
writeln('CA.DB.');
writeln('CCCDDD');
writeln('C..D..');
end;
if (m=5) and (n=7) then
begin
writeln(5);
writeln('AAABBB.');
writeln('.A..BD.');
writeln('CA.EBD.');
writeln('CCCEDDD');
writeln('C.EEE..');
end;
if (m=5) and (n=8) then
begin
writeln(6);
writeln('AAABBB.C');
writeln('.A..BCCC');
writeln('DA.EB.FC');
writeln('DDDEEEF.');
writeln('D..E.FFF');
end;
if (m=5) and (n=9) then
begin
writeln(7);
writeln('AAABBBC..');
writeln('.A..BECCC');
writeln('DA.FBECG.');
writeln('DDDFEEEG.');
writeln('D.FFF.GGG');
end;
if (m=6) and (n=1) then
begin
writeln(0);
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
end;
if (m=6) and (n=2) then
begin
writeln(0);
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
end;
if (m=6) and (n=3) then
begin
writeln(2);
writeln('AAA');
writeln('.A.');
writeln('BA.');
writeln('BBB');
writeln('B..');
writeln('...');
end;
if (m=6) and (n=4) then
begin
writeln(3);
writeln('AAA.');
writeln('.A..');
writeln('BA..');
writeln('BBBC');
writeln('BCCC');
writeln('...C');
end;
if (m=6) and (n=5) then
begin
writeln(4);
writeln('AAA..');
writeln('.ABBB');
writeln('CA.B.');
writeln('CCCBD');
writeln('C.DDD');
writeln('....D');
end;
if (m=6) and (n=6) then
begin
writeln(5);
writeln('AAABBB');
writeln('.AC.B.');
writeln('.AC.B.');
writeln('DCCC.E');
writeln('DDDEEE');
writeln('D....E');
end;
if (m=6) and (n=7) then
begin
writeln(6);
writeln('AAA.BBB');
writeln('.AC..B.');
writeln('.ACCCB.');
writeln('E.CFDDD');
writeln('EEEF.D.');
writeln('E.FFFD.');
end;
if (m=6) and (n=8) then
begin
writeln(7);
writeln('AAABBB..');
writeln('.AD.BCCC');
writeln('.AD.B.C.');
writeln('EDDDG.CF');
writeln('EEE.GFFF');
writeln('E..GGG.F');
end;
if (m=6) and (n=9) then
begin
writeln(8);
writeln('AAABBBCCC');
writeln('.AD.B..C.');
writeln('.AD.BE.C.');
writeln('FDDDHEEEG');
writeln('FFF.HEGGG');
writeln('F..HHH..G');
end;
if (m=7) and (n=1) then
begin
writeln(0);
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
end;
if (m=7) and (n=2) then
begin
writeln(0);
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
end;
if (m=7) and (n=3) then
begin
writeln(3);
writeln('AAA');
writeln('.A.');
writeln('BA.');
writeln('BBB');
writeln('B.C');
writeln('CCC');
writeln('..C');
end;
if (m=7) and (n=4) then
begin
writeln(4);
writeln('AAA.');
writeln('.AB.');
writeln('.AB.');
writeln('CBBB');
writeln('CCCD');
writeln('CDDD');
writeln('...D');
end;
if (m=7) and (n=5) then
begin
writeln(5);
writeln('AAA..');
writeln('.ABBB');
writeln('CA.B.');
writeln('CCCB.');
writeln('CEDDD');
writeln('.E.D.');
writeln('EEED.');
end;
if (m=7) and (n=6) then
begin
writeln(6);
writeln('AAABBB');
writeln('.A..B.');
writeln('CA.DB.');
writeln('CCCDDD');
writeln('CE.DF.');
writeln('.EEEF.');
writeln('.E.FFF');
end;
if (m=7) and (n=7) then
begin
writeln(8);
writeln('AAA.BBB');
writeln('.ACCCB.');
writeln('DA.C.BE');
writeln('DDDCEEE');
writeln('DGFFFHE');
writeln('.G.F.H.');
writeln('GGGFHHH');
end;
if (m=7) and (n=8) then
begin
writeln(9);
writeln('AAA.BBB.');
writeln('.ACCCBE.');
writeln('.ADC.BE.');
writeln('DDDCFEEE');
writeln('G.DIFFFH');
writeln('GGGIFHHH');
writeln('G.III..H');
end;
if (m=7) and (n=9) then
begin
writeln(10);
writeln('AAA.BBB..');
writeln('.ACCCBDDD');
writeln('EA.C.BFD.');
writeln('EEECFFFD.');
writeln('EIGGGJF.H');
writeln('.I.G.JHHH');
writeln('IIIGJJJ.H');
end;
if (m=8) and (n=1) then
begin
writeln(0);
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
end;
if (m=8) and (n=2) then
begin
writeln(0);
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
end;
if (m=8) and (n=3) then
begin
writeln(3);
writeln('AAA');
writeln('.A.');
writeln('BA.');
writeln('BBB');
writeln('B..');
writeln('CCC');
writeln('.C.');
writeln('.C.');
end;
if (m=8) and (n=4) then
begin
writeln(4);
writeln('AAA.');
writeln('.A..');
writeln('BA..');
writeln('BBB.');
writeln('BCCC');
writeln('.DC.');
writeln('.DC.');
writeln('DDD.');
end;
if (m=8) and (n=5) then
begin
writeln(6);
writeln('AAA..');
writeln('.ABBB');
writeln('CA.B.');
writeln('CCCBD');
writeln('C.DDD');
writeln('EEEFD');
writeln('.E.F.');
writeln('.EFFF');
end;
if (m=8) and (n=6) then
begin
writeln(7);
writeln('AAABBB');
writeln('.A..B.');
writeln('CA.DB.');
writeln('CCCDDD');
writeln('C.ED..');
writeln('.GEEEF');
writeln('.GEFFF');
writeln('GGG..F');
end;
if (m=8) and (n=7) then
begin
writeln(9);
writeln('AAA.BBB');
writeln('.ACCCB.');
writeln('DA.CEB.');
writeln('DDDCEEE');
writeln('DFFFE.G');
writeln('.IFHGGG');
writeln('.IFHHHG');
writeln('IIIH...');
end;
if (m=8) and (n=8) then
begin
writeln(10);
writeln('AAABBB..');
writeln('.A..BCCC');
writeln('DA..B.C.');
writeln('DDDEEECG');
writeln('DFFFEGGG');
writeln('.IFHE.JG');
writeln('.IFHHHJ.');
writeln('IIIH.JJJ');
end;
if (m=8) and (n=9) then
begin
writeln(12);
writeln('AAABBB..C');
writeln('.AE.BDCCC');
writeln('.AE.BDDDC');
writeln('GEEEHDFFF');
writeln('GGGIHHHF.');
writeln('GK.IHL.FJ');
writeln('.KIIILJJJ');
writeln('KKK.LLL.J');
end;
if (m=9) and (n=1) then
begin
writeln(0);
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
writeln('.');
end;
if (m=9) and (n=2) then
begin
writeln(0);
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
writeln('..');
end;
if (m=9) and (n=3) then
begin
writeln(4);
writeln('AAA');
writeln('.A.');
writeln('BA.');
writeln('BBB');
writeln('B.C');
writeln('CCC');
writeln('D.C');
writeln('DDD');
writeln('D..');
end;
if (m=9) and (n=4) then
begin
writeln(5);
writeln('AAA.');
writeln('.A..');
writeln('BA..');
writeln('BBBC');
writeln('BCCC');
writeln('DDDC');
writeln('.DE.');
writeln('.DE.');
writeln('.EEE');
end;
if (m=9) and (n=5) then
begin
writeln(7);
writeln('AAA..');
writeln('.ABBB');
writeln('CA.B.');
writeln('CCCBD');
writeln('CEDDD');
writeln('.EEED');
writeln('GEFFF');
writeln('GGGF.');
writeln('G..F.');
end;
if (m=9) and (n=6) then
begin
writeln(8);
writeln('AAABBB');
writeln('.A..B.');
writeln('CA.DB.');
writeln('CCCDDD');
writeln('C.ED..');
writeln('EEEFFF');
writeln('G.EHF.');
writeln('GGGHF.');
writeln('G.HHH.');
end;
if (m=9) and (n=7) then
begin
writeln(10);
writeln('AAABBB.');
writeln('.A..BD.');
writeln('CA.EBD.');
writeln('CCCEDDD');
writeln('CFEEE.G');
writeln('.FFFGGG');
writeln('IFHHHJG');
writeln('IIIH.J.');
writeln('I..HJJJ');
end;
if (m=9) and (n=8) then
begin
writeln(12);
writeln('AAABBB.C');
writeln('.AD.BCCC');
writeln('.AD.B.EC');
writeln('FDDDEEE.');
writeln('FFFGGGEI');
writeln('FHHHGIII');
writeln('.KHJG.LI');
writeln('.KHJJJL.');
writeln('KKKJ.LLL');
end;
if (m=9) and (n=9) then
begin
writeln(13);
writeln('AAABBBCCC');
writeln('.AD.BE.C.');
writeln('.AD.BE.C.');
writeln('FDDDEEE.H');
writeln('FFFGGGHHH');
writeln('FIIIGJJJH');
writeln('.LIKG.JM.');
writeln('.LIKKKJM.');
writeln('LLLK..MMM');
end;
end.