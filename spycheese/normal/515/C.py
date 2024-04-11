import math
from functools import reduce

a = reduce(lambda a, b: a * b, map(lambda x: math.factorial(int(x)), (input(), input())[1]), 1)
while a % 7 == 0:
    a //= math.factorial(7)
    print("7", end="")
while a % 5 == 0:
    a //= math.factorial(5)
    print("5", end="")
while a % 3 == 0:
    a //= math.factorial(3)
    print("3", end="")
while a % 2 == 0:
    a //= math.factorial(2)
    print("2", end="")