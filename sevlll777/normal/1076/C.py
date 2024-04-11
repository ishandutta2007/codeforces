for u in range(int(input())):
    d = int(input())
    if 0 < d < 4:
        print("N")
    else:
        print("Y", (d+(d*d-4*d)**0.5)/2, d - (d+(d*d-4*d)**0.5)/2)