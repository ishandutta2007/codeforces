x1,y1=(int(z) for z in input().split())
x2,y2=(int(z) for z in input().split())
x3,y3=(int(z) for z in input().split())

v1x=x2-x1
v1y=y2-y1

v2x=x3-x1
v2y=y3-y1

print(3)
print(x1+v1x+v2x,y1+v1y+v2y)
print(x1+v1x-v2x,y1+v1y-v2y)
print(x1-v1x+v2x,y1-v1y+v2y)