d={"monday":1,"tuesday":2,"wednesday":3,"thursday":4,"friday":5,"saturday":6,"sunday":7}

a=d[input()]
b=d[input()]
if b>=a and b-a in [0,2,3]:
    print("YES")
elif b<a and b-a in [-4,-5]:
    print("YES")
else:
    print("NO")