using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        Console.ReadLine();
        var s = Console.ReadLine().Split(' ').Select(int.Parse).OrderBy(x => x).ToArray();
        Console.WriteLine(String.Join(" ", s));
    }
}