n=input()
def gcd (a, b):
    return a if b == 0 else gcd (b, a % b)
print n * reduce (gcd, map (int, raw_input().split()))