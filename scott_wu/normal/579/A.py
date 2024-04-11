def g(x):
    if x == 0:
        return 0
    return g(x//2) if x % 2 == 0 else g((x-1)//2) + 1

print(g(int(input())))