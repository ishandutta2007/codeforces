import re,sys
class INT:
    def __init__(self,a):
        if isinstance(a,INT):
            self.v=a.v
        else:
            self.v=int(a)
    def __add__(self,a):
        return INT((self.v+a.v)&32767)
    def __sub__(self,a):
        return INT((self.v-a.v)&32767)
    def __mul__(self,a):
        return INT((self.v*a.v)&32767)
    def __div__(self,a):
        return INT((self.v/a.v)&32767)
    def __eq__(self,a):
        return self.v==a.v
    def __gt__(self,a):
        return self.v>a.v
    def __lt__(self,a):
        return self.v<a.v
    def __and__(self,a):
        return INT(self.v&a.v)
n=input()
s="".join(sys.stdin.readlines())
s=s.replace("\n","")
s=s.replace("{","")
s=s.replace("}","")
s=s.replace("int f(int n)","");
s=re.sub("([0-9]+)","INT(\\1)",s)
s="a=[-1]*33000\ndef f(n):\n\tn=INT(n);if(a[n.v]!=-1)return a[n.v];"+s
s=re.sub("return(.*?);","return INT(\\1);",s)
s=s.replace(";","\n\t")
s=s.replace("return",":return")
for i in xrange(10):
    s=s.replace("\t ","\t").replace("\t:","\t")
s+="\n"
s+="k=-1\nfor i in xrange(32768):\n\ta[i]=f(i).v\n\tif a[i]==n:\n\t\tk=i\nprint k"
exec s