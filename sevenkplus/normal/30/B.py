aa,ab,ac=map(int,raw_input().split("."))
mo=[0,31,28,31,30,31,30,31,31,30,31,30,31]
mr=[0,31,29,31,30,31,30,31,31,30,31,30,31]
def chk(a,b,c):
    if (b==0) or (a==0):
        return False
    if b>12:
        return False
    if c%4==0:
        if mr[b]<a:
            return False
    if c%4!=0:
        if mo[b]<a:
            return False
    if ac-c>18:
        return True
    if ac-c<18:
        return False
    if (ab>b) or ((ab==b) and (aa>=a)):
        return True
    else:
        return False
ba,bb,bc=map(int,raw_input().split("."))
if chk(ba,bb,bc) or chk(bb,bc,ba) or chk(bc,ba,bb) or chk(ba,bc,bb) or chk(bc,bb,ba) or chk(bb,ba,bc):
    print "YES"
else:
    print "NO"