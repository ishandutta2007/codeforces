a,b = map(int,raw_input().split(":"))
c,d = map(int,raw_input().split(":"))
a-=c
b-=d
if b < 0:
  b += 60
  a -= 1
if a < 0:
  a += 24

print "%02d:%02d\n" % (a , b)