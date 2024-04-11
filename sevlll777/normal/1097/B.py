n=int(input())
mass=[]
coco = [0]
for u in range(n):
    mass.append(int(input()))
for eq in range(len(mass)):
    for el in range(len(coco)):
        coco[el] += mass[eq]
        coco[el]%=360
        coco.append(coco[el]-2*mass[eq])
if 0 in coco:
    print('YES')
else:
    print('NO')